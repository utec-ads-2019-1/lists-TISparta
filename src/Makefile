IDIR = ../include
CXX = g++
CXXFLAGS = -w -O2 -I $(IDIR)

ODIR = obj

_DEPS = bidirectional_iterator.h circular.h forward.h \
				forward_iterator.h iterator.h linked.h list.h \
				node.h color.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o tester.o mocker.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

run: $(OBJ) $(DEPS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(ODIR):
	mkdir $@

$(ODIR)/main.o: main.cpp $(DEPS) | $(ODIR)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(ODIR)/%.o: %.cpp $(DEPS) | $(ODIR)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -rf $(ODIR)
	rm sort


