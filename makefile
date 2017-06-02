# Based on http://www.puxan.com/web/howto-write-generic-makefiles/
EXECUTABLE = kozrum.exe
CXXFLAGS = -std=c++11

INCLUDES := -I /usr/include/boost/
LIBRARIES = -lcurl -lboost_program_options
SOURCES = $(wildcard src/*.cpp)
BIN = bin
OBJECTS = $(SOURCES:.cpp=.o)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) $(INCLUDES) -o $(EXECUTABLE) $(LIBRARIES)
	mv src/*.o $(BIN)/
	sudo cp $(EXECUTABLE) /usr/bin/kozrum
	# sudo mkdir -p /etc/kozrum
	# sudo cp src/*.py /usr/bin/kozrum_includes/*.py

%.o: %.cpp
	$(CXX) -c $(CXX_FLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(BIN)/*.o
