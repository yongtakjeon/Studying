#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include "SongCollection.h"
#include "SongCollection.h"


void printbar(std::ostream& out = std::cout)
{
	out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
}

void printHeader(const char* title, std::ostream& out = std::cout)
{
	printbar(out);
	out << "| " << std::left << std::setw(85) << title << std::right << "|\n";
	printbar(out);
}

int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::SongCollection theCollection(argv[1]);

	printHeader("The original collection");
	theCollection.display(std::cout);
	printbar();

	
	printHeader("The collection sorted by title");
	theCollection.sort("title");
	theCollection.display(std::cout);
	printbar();

	printHeader("The collection sorted by length");
	theCollection.sort("title");
	theCollection.sort("length");
	theCollection.display(std::cout);
	printbar();


	printHeader("The collection with fixed album names");
	theCollection.cleanAlbum();
	theCollection.display(std::cout);
	printbar();

	{
		// looking for "The Beatles" in the collection
		if (theCollection.inCollection("The Beatles"))
			std::cout << "There are songs of \"The Beatles\" in collection.\n";
		else
			std::cout << "There are no songs of \"The Beatles\" in collection.\n";
	}

	{
		// look for Sia; increase the price of each song by 5 cents
		if (theCollection.inCollection("Sia"))
		{
			printHeader("Songs of \"Sia\"");
			auto sia = theCollection.getSongsForArtist("Sia");
			for (auto& song : sia)
			{
				std::cout << song << "\n";
				song.m_price += 10;
			}
			printbar();
		}
	}
}


/* EXPECTED OUTPUT:

Command Line:
--------------------------
  1: ./a.out
  2: songs.txt
--------------------------

----------------------------------------------------------------------------------------
| The original collection                                                              |
----------------------------------------------------------------------------------------
| Bird Set Free        | Sia             | This Is Acting       |   2016 | 4:12 | 1.21 |
| Fight Song           | Rachel Platten  | [None]               |   2015 | 3:24 | 1.25 |
| ..Baby One More Time | Britney Spears  | [None]               |   1999 | 3:30 | 1.29 |
| One Million Bullets  | Sia             | This Is Acting       |   2016 | 4:12 | 1.23 |
| (You Drive Me) Crazy | Britney Spears  | Baby One More Time   |   1999 | 3:18 | 1.29 |
| Cheap Thrills        | Sia             | This Is Acting       |   2016 | 3:31 | 1.29 |
| Dream On             | Amy Macdonald   | Under Stars          |   2017 | 3:19 | 1.29 |
| Dream Is Collapsing  | Hans Zimmer     | Best of              |   2014 | 2:23 | 1.29 |
| Hot N Cold           | Katy Perry      | [None]               |   2008 | 3:40 | 1.14 |
| Circus               | Britney Spears  | Circus               |   2008 | 3:12 | 1.29 |
| Under Stars          | Amy Macdonald   | Under Stars          |   2017 | 3:41 | 1.29 |
| Rafiki's Fireflies   | Hans Zimmer     | Best of              |   2017 | 1:52 | 1.29 |
| Song Of Ocarina      | Diego Modena    | [None]               |   1991 | 3:35 | 0.49 |
| Sometimes            | Britney Spears  | Baby One More Time   |   1999 | 4:05 | 1.29 |
| Alive                | Sia             | This Is Acting       |   2016 | 4:23 | 1.22 |
| Why so Serious?      | Hans Zimmer     | Best of              |   2016 | 9:14 | 1.29 |
| Ain't It Funny       | Jennifer Lopez  | [None]               |        | 4:17 | 0.99 |
| Chandelier           | Sia             | [None]               |   2014 | 3:36 | 1.32 |
| Break the Ice        | Britney Spears  | Blackout             |   2007 | 3:16 | 1.29 |
| Moonlight Reggae     | Diego Modena    | [None]               |   2010 | 4:43 | 1.19 |
----------------------------------------------------------------------------------------
|                                                        Total Listening Time: 1:17:23 |
----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
| The collection sorted by title                                                       |
----------------------------------------------------------------------------------------
| (You Drive Me) Crazy | Britney Spears  | Baby One More Time   |   1999 | 3:18 | 1.29 |
| ..Baby One More Time | Britney Spears  | [None]               |   1999 | 3:30 | 1.29 |
| Ain't It Funny       | Jennifer Lopez  | [None]               |        | 4:17 | 0.99 |
| Alive                | Sia             | This Is Acting       |   2016 | 4:23 | 1.22 |
| Bird Set Free        | Sia             | This Is Acting       |   2016 | 4:12 | 1.21 |
| Break the Ice        | Britney Spears  | Blackout             |   2007 | 3:16 | 1.29 |
| Chandelier           | Sia             | [None]               |   2014 | 3:36 | 1.32 |
| Cheap Thrills        | Sia             | This Is Acting       |   2016 | 3:31 | 1.29 |
| Circus               | Britney Spears  | Circus               |   2008 | 3:12 | 1.29 |
| Dream Is Collapsing  | Hans Zimmer     | Best of              |   2014 | 2:23 | 1.29 |
| Dream On             | Amy Macdonald   | Under Stars          |   2017 | 3:19 | 1.29 |
| Fight Song           | Rachel Platten  | [None]               |   2015 | 3:24 | 1.25 |
| Hot N Cold           | Katy Perry      | [None]               |   2008 | 3:40 | 1.14 |
| Moonlight Reggae     | Diego Modena    | [None]               |   2010 | 4:43 | 1.19 |
| One Million Bullets  | Sia             | This Is Acting       |   2016 | 4:12 | 1.23 |
| Rafiki's Fireflies   | Hans Zimmer     | Best of              |   2017 | 1:52 | 1.29 |
| Sometimes            | Britney Spears  | Baby One More Time   |   1999 | 4:05 | 1.29 |
| Song Of Ocarina      | Diego Modena    | [None]               |   1991 | 3:35 | 0.49 |
| Under Stars          | Amy Macdonald   | Under Stars          |   2017 | 3:41 | 1.29 |
| Why so Serious?      | Hans Zimmer     | Best of              |   2016 | 9:14 | 1.29 |
----------------------------------------------------------------------------------------
|                                                        Total Listening Time: 1:17:23 |
----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
| The collection sorted by length                                                      |
----------------------------------------------------------------------------------------
| Rafiki's Fireflies   | Hans Zimmer     | Best of              |   2017 | 1:52 | 1.29 |
| Dream Is Collapsing  | Hans Zimmer     | Best of              |   2014 | 2:23 | 1.29 |
| Circus               | Britney Spears  | Circus               |   2008 | 3:12 | 1.29 |
| Break the Ice        | Britney Spears  | Blackout             |   2007 | 3:16 | 1.29 |
| (You Drive Me) Crazy | Britney Spears  | Baby One More Time   |   1999 | 3:18 | 1.29 |
| Dream On             | Amy Macdonald   | Under Stars          |   2017 | 3:19 | 1.29 |
| Fight Song           | Rachel Platten  | [None]               |   2015 | 3:24 | 1.25 |
| ..Baby One More Time | Britney Spears  | [None]               |   1999 | 3:30 | 1.29 |
| Cheap Thrills        | Sia             | This Is Acting       |   2016 | 3:31 | 1.29 |
| Song Of Ocarina      | Diego Modena    | [None]               |   1991 | 3:35 | 0.49 |
| Chandelier           | Sia             | [None]               |   2014 | 3:36 | 1.32 |
| Hot N Cold           | Katy Perry      | [None]               |   2008 | 3:40 | 1.14 |
| Under Stars          | Amy Macdonald   | Under Stars          |   2017 | 3:41 | 1.29 |
| Sometimes            | Britney Spears  | Baby One More Time   |   1999 | 4:05 | 1.29 |
| Bird Set Free        | Sia             | This Is Acting       |   2016 | 4:12 | 1.21 |
| One Million Bullets  | Sia             | This Is Acting       |   2016 | 4:12 | 1.23 |
| Ain't It Funny       | Jennifer Lopez  | [None]               |        | 4:17 | 0.99 |
| Alive                | Sia             | This Is Acting       |   2016 | 4:23 | 1.22 |
| Moonlight Reggae     | Diego Modena    | [None]               |   2010 | 4:43 | 1.19 |
| Why so Serious?      | Hans Zimmer     | Best of              |   2016 | 9:14 | 1.29 |
----------------------------------------------------------------------------------------
|                                                        Total Listening Time: 1:17:23 |
----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
| The collection with fixed album names                                                |
----------------------------------------------------------------------------------------
| Rafiki's Fireflies   | Hans Zimmer     | Best of              |   2017 | 1:52 | 1.29 |
| Dream Is Collapsing  | Hans Zimmer     | Best of              |   2014 | 2:23 | 1.29 |
| Circus               | Britney Spears  | Circus               |   2008 | 3:12 | 1.29 |
| Break the Ice        | Britney Spears  | Blackout             |   2007 | 3:16 | 1.29 |
| (You Drive Me) Crazy | Britney Spears  | Baby One More Time   |   1999 | 3:18 | 1.29 |
| Dream On             | Amy Macdonald   | Under Stars          |   2017 | 3:19 | 1.29 |
| Fight Song           | Rachel Platten  |                      |   2015 | 3:24 | 1.25 |
| ..Baby One More Time | Britney Spears  |                      |   1999 | 3:30 | 1.29 |
| Cheap Thrills        | Sia             | This Is Acting       |   2016 | 3:31 | 1.29 |
| Song Of Ocarina      | Diego Modena    |                      |   1991 | 3:35 | 0.49 |
| Chandelier           | Sia             |                      |   2014 | 3:36 | 1.32 |
| Hot N Cold           | Katy Perry      |                      |   2008 | 3:40 | 1.14 |
| Under Stars          | Amy Macdonald   | Under Stars          |   2017 | 3:41 | 1.29 |
| Sometimes            | Britney Spears  | Baby One More Time   |   1999 | 4:05 | 1.29 |
| Bird Set Free        | Sia             | This Is Acting       |   2016 | 4:12 | 1.21 |
| One Million Bullets  | Sia             | This Is Acting       |   2016 | 4:12 | 1.23 |
| Ain't It Funny       | Jennifer Lopez  |                      |        | 4:17 | 0.99 |
| Alive                | Sia             | This Is Acting       |   2016 | 4:23 | 1.22 |
| Moonlight Reggae     | Diego Modena    |                      |   2010 | 4:43 | 1.19 |
| Why so Serious?      | Hans Zimmer     | Best of              |   2016 | 9:14 | 1.29 |
----------------------------------------------------------------------------------------
|                                                        Total Listening Time: 1:17:23 |
----------------------------------------------------------------------------------------
There are no songs of "The Beatles" in collection.
----------------------------------------------------------------------------------------
| Songs of "Sia"                                                                       |
----------------------------------------------------------------------------------------
| Cheap Thrills        | Sia             | This Is Acting       |   2016 | 3:31 | 1.29 |
| Chandelier           | Sia             |                      |   2014 | 3:36 | 1.32 |
| Bird Set Free        | Sia             | This Is Acting       |   2016 | 4:12 | 1.21 |
| One Million Bullets  | Sia             | This Is Acting       |   2016 | 4:12 | 1.23 |
| Alive                | Sia             | This Is Acting       |   2016 | 4:23 | 1.22 |
----------------------------------------------------------------------------------------

*/