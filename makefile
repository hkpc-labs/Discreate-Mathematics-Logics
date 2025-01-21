CXX = g++
CXXFLAGS = -std=c++23 -g -O3
EXECUTABLE = main
HEADERDIR = include
SRCDIR = src
TEMPDIR = .temp
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(TEMPDIR)/%.o,$(SOURCES))
INCLUDES = -I$(HEADERDIR)

$(TEMPDIR):
	mkdir -p $@

$(TEMPDIR)/%.o: $(SRCDIR)/%.cpp | $(TEMPDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(TEMPDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

all: $(TEMPDIR)/$(EXECUTABLE)
run: $(TEMPDIR)/$(EXECUTABLE)
	./$(TEMPDIR)/$(EXECUTABLE)
clean:
	rm -rf $(TEMPDIR)

.PHONY: all clean