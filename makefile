CXX = g++
CXXFLAGS = -std=c++14 -Werror -Wuninitialized
SRCDIR = src
BUILDDIR = build
TESTDIR = test-io
INPUTDIR = $(TESTDIR)/input-files
OUTPUTDIR = $(TESTDIR)/output-files
EXPECTEDDIR = $(TESTDIR)/expected-output-files

# List of test numbers
TESTS = 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18

.PHONY: all clean

all: $(addprefix test, $(TESTS))

clean:
	rm -rf $(BUILDDIR)/* $(OUTPUTDIR)/*

define run_test
test$(1): $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILDDIR)/test_io $(SRCDIR)/main.cpp
	$(BUILDDIR)/test_io < $(INPUTDIR)/$(1).txt > $(OUTPUTDIR)/$(1).txt
	diff -w $(EXPECTEDDIR)/$(1).txt $(OUTPUTDIR)/$(1).txt
endef

$(foreach test,$(TESTS),$(eval $(call run_test,$(test))))
