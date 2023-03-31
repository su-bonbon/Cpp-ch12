pa12: Container.o pa12.o
	$(CXX) $(CXXFLAGS) Container.o pa12.o -o pa12

Container.o: Container.h Container.cpp
	$(CXX) $(CXXFLAGS) Container.cpp -c

pa12.o: pa12.cpp Container.h
	$(CXX) $(CXXFLAGS) pa12.cpp -c

clean:
	rm -f Container.o pa12.o pa12

turnin:
	turnin -c cs202 -p pa12 -v \
		Container.h Container.cpp pa12.cpp Makefile

