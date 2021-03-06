EXEC = mandelbrot
INCDIR = include/
BUILDDIR = build/
SRCDIR = src/
CXX = $$mkCxxCompiler
CXXFLAGS = -Wall -g -std=c++11
CPPFLAGS = -I$(INCDIR)
SOURCES = $(wildcard $(SRCDIR)*.cpp)
HEADERS = $(wildcard $(INCDIR)*.hpp)
OBJS = $(patsubst $(SRCDIR)%.cpp, $(BUILDDIR)%.o, $(SOURCES))
RM = -rm -rf

$(EXEC): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)
	
$(BUILDDIR)%.o: $(SRCDIR)%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	$(RM) $(BUILDDIR)* $(SRCDIR)*~ $(INCDIR)*~ *~
