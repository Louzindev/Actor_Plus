all:
	cd build 
	cmake .. && cmake --build .

debug:
	cd test 
	sampctl p build && sampctl p run

clean:
	cd test && cd plugins 
	rm -r Debug

linux:
	debian
	rm -rf Actor_Plus
	git clone https://github.com/LouzinDeev/Actor_Plus.git
	cd Actor_Plus && cd Actor_Plus
	git submodule init && git submodule update
	rm -rf build && cd build
	cmake .. && cmake --build .
	

