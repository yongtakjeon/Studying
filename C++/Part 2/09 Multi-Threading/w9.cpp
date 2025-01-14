// Workshop 9 - Multi-Threading
// w9.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "SecureData.h"
#include "SecureData.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl << endl;

	if (argc != 4)
	{
		cerr << endl << "***Incorrect number of arguments***" << endl;
		return 1;
	}

    char key = argv[3][0];

    try {
        w9::SecureData sd(argv[1], key, &cout);
        sd.backup(argv[2]);

        sd.restore(argv[2], key);
        cout << sd << std::endl;

    } catch (const std::string& msg) {
        cout << msg << std::endl;
    }

	return 0;
}


/* EXPECTED OUTPUT:

Command Line: ./a.out input.txt encoded.dat.txt K


1935 bytes copied from file input.txt into memory (null byte added)
Data encrypted in memory

1936 bytes copied from binary file encoded.dat.txt into memory.
Data decrypted in memory

C++ is a general-purpose programming language created by
Bjarne Stroustrup as an extension of the C programming language,
or "C with Classes". The language has expanded significantly
over time, and modern C++ has object-oriented, generic,
and functional features in addition to facilities for
low-level memory manipulation. It is almost always
implemented as a compiled language, and many vendors provide
C++ compilers, including the Free Software Foundation, LLVM,
Microsoft, Intel, Oracle, and IBM, so it is available on
many platforms.

C++ was designed with a bias toward system programming and
embedded, resource-constrained software and large systems,
with performance, efficiency, and flexibility of use as its
design highlights. C++ has also been found useful in many
other contexts, with key strengths being software
infrastructure and resource-constrained applications,
including desktop applications, servers (e.g. e-commerce,
Web search, or SQL servers), and performance-critical
applications (e.g. telephone switches or space probes).

C++ is standardized by the International Organization for
Standardization (ISO), with the latest standard version
ratified and published by ISO in December 2017 as
ISO/IEC 14882:2017 (informally known as C++17). The C++
programming language was initially standardized in 1998
as ISO/IEC 14882:1998, which was then amended by the
C++03, C++11 and C++14 standards. The current C++17
standard supersedes these with new features and an
enlarged standard library. Before the initial
standardization in 1998, C++ was developed by Danish
computer scientist Bjarne Stroustrup at Bell Labs
since 1979 as an extension of the C language; he
wanted an efficient and flexible language similar to C
that also provided high-level features for program
organization. C++20 is the next planned standard,
keeping with the current trend of a new version every
three years.


*/