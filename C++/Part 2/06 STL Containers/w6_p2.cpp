#include <iostream>
#include <iomanip>
#include <fstream>
#include "Autoshop.h"
#include "Autoshop.h"
#include "Utilities.h"
#include "Utilities.h"


void loadData(const char* filename, sdds::Autoshop& as)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
		return;
	}
	while (file)
	{
		// TODO: This code can throw errors to signal that something went wrong while
		//         extracting data. Write code to catch and handle the following errors:
		//       - the type of vehicle is not recognized: the first non-empty character
		//           on the line is not 'c', 'C', 'r', or 'R'. In this case print
		//           "Unrecognized record type: [TAG]<endl>"
		//       - one of the fields in the record contains invalid data. In this case print
		//           "Invalid record!<endl>"

		try
		{
			sdds::Vehicle* aVehicle = sdds::createInstance(file);
			if (aVehicle)
				as += aVehicle;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
		catch (char tag)
		{
			cout << "Unrecognized record type: [" << tag << "]" << endl;
		}
		
	}
}

// ws dataClean.txt dataMessy.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::Autoshop as;
	loadData(argv[1], as);
	as.display(std::cout);
	std::cout << "\n";
	loadData(argv[2], as);
	as.display(std::cout);

	std::cout << std::endl;
	std::list<const sdds::Vehicle*> vehicles;
	{
		// TODO: Create a lambda expression that receives as parameter `const sdds::Vehicle*`
		//         and returns true if the vehicle has a top speed >300km/h
		auto fastVehicles = [](const sdds::Vehicle* vehicle)
		{
			return vehicle->topSpeed() > 300;
		};
		as.select(fastVehicles, vehicles);
		std::cout << "--------------------------------\n";
		std::cout << "|       Fast Vehicles          |\n";
		std::cout << "--------------------------------\n";
		for (auto it = vehicles.begin(); it != vehicles.end(); ++it)
		{
			(*it)->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "--------------------------------\n";
	}

	vehicles.clear();
	std::cout << std::endl;
	{
		// TODO: Create a lambda expression that receives as parameter `const sdds::Vehicle*`
		//         and returns true if the vehicle is broken and needs repairs.
		auto brokenVehicles = [](const sdds::Vehicle* vehicle)
		{
			return vehicle->condition() == "broken";
		};
		as.select(brokenVehicles, vehicles);
		std::cout << "--------------------------------\n";
		std::cout << "| Vehicles in need of repair   |\n";
		std::cout << "--------------------------------\n";
		for (const auto vehicle : vehicles)
		{
			vehicle->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "--------------------------------\n";
	}

	return 0;
}


/* EXPECTED OUTPUT:
Command Line:
--------------------------
  1: ./a.out
  2: dataClean.txt
  3: dataMessy.txt
--------------------------

--------------------------------
| Cars in the autoshop!        |
--------------------------------
|     Toyota | new    | 157.00 |
|     Jaguar | used   | 295.20 |*
|      Honda | broken | 145.00 |
|     Porche | used   | 365.40 |*
|   Chrysler | new    | 173.00 |
--------------------------------

Invalid record!
Invalid record!
Unrecognized record type: [t]
--------------------------------
| Cars in the autoshop!        |
--------------------------------
|     Toyota | new    | 157.00 |
|     Jaguar | used   | 295.20 |*
|      Honda | broken | 145.00 |
|     Porche | used   | 365.40 |*
|   Chrysler | new    | 173.00 |
| Alfa Romeo | new    | 176.00 |
|       Ford | new    | 162.00 |
|   Red Bull | broken | 346.56 |*
|    Ferrari | new    | 367.33 |*
--------------------------------

--------------------------------
|       Fast Vehicles          |
--------------------------------
|     Porche | used   | 365.40 |*
|   Red Bull | broken | 346.56 |*
|    Ferrari | new    | 367.33 |*
--------------------------------

--------------------------------
| Vehicles in need of repair   |
--------------------------------
|      Honda | broken | 145.00 |
|   Red Bull | broken | 346.56 |*
--------------------------------

*/