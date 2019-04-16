IDIR = ../include
CXX = g++
CXXFLAGS = -std=c++11 -w -O2 -I $(IDIR)

ODIR = obj

_LISTS = circular.h linked.h forward.h list.h
_ITERATORS = bidirectional_iterator.h forward_iterator.h
_TEST = color.h mocker.h tester.h

LISTS = $(patsubst %,$(IDIR)/lists/%,$(_LISTS))
ITERATORS = $(patsubst %,$(IDIR)/iterators/%,$(_ITERATORS))
TEST = $(patsubst %,$(IDIR)/test/%,$(_TEST))

_OBJ = main.o tester.o mocker.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

run: $(OBJ)
	$(CXX) -o $@ $(OBJ) $(CXXFLAGS)

$(ODIR):
	mkdir $@

$(ODIR)/main.o: main.cpp tester.cpp | $(ODIR)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(ODIR)/tester.o: tester.cpp $(TEST) $(LISTS) $(ITERATORS) | $(ODIR)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(ODIR)/mocker.o: mocker.cpp | $(ODIR)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -rf $(ODIR)
	rm run
