main: main.cpp io-module
	bash measure.sh g++ main.cpp -std=c++2a -fmodules-ts

main2: main2.cpp io-module
	bash measure.sh g++ main2.cpp -std=c++2a -fmodules-ts

io-module:
	g++ io.hpp -std=c++2a -fmodule-header

.PHONY : clean

clean:
	rm -rf gcm.cache a.out
