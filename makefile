# Based on http://www.puxan.com/web/howto-write-generic-makefiles/
EXECUTABLE = kozrum.exe
CXXFLAGS = -std=c++11

SOURCES = $(wildcard src/*.cpp)
BIN = bin
OBJECTS = $(SOURCES:.cpp=.o)
LIBRARIES =

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE) $(LIBRARIES)
	mv src/*.o bin/

%.o: %.cpp
	$(CXX) -c $(CXX_FLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(BIN)/*.o