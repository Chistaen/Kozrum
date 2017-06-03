# Based on http://www.puxan.com/web/howto-write-generic-makefiles/
EXECUTABLE 	= kozrum.exe
CXXFLAGS 	= -std=c++11

INCLUDES 	= -I/usr/include/boost -I/usr/include/python3.6m
LIBRARIES 	= -lcurl -lboost_program_options -lpython3.6m
SOURCES 	= $(wildcard src/*.cpp)
BIN 		= bin
OBJECTS 	= $(SOURCES:.cpp=.o)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) $(INCLUDES) -o $(EXECUTABLE) $(LIBRARIES)
	mv src/*.o $(BIN)/
	sudo cp $(EXECUTABLE) /usr/bin/kozrum
	sudo mkdir -p /usr/lib/kozrum
	sudo cp lib/*.py /usr/lib/kozrum_includes

%.o: %.cpp
	$(CXX) $(INCLUDES) -c $(CXX_FLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(BIN)/*.o
