test:
	g++ -std=c++17 *.cpp && ./a.out


main:
	g++ -std=c++17 `ls *.cpp | grep -v test` && ./a.out
