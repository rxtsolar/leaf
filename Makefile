LIBS := $(shell pkg-config opencv --libs)
FLAG := $(shell pkg-config opencv --cflags)
FLAG +=

SRC := svm.cpp classifier.cpp feature.cpp train.cpp

all:
	g++ $(FLAG) extract.cpp $(SRC) -o extract $(LIBS)
	g++ $(FLAG) main.cpp $(SRC) -o test $(LIBS)
