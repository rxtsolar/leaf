LIBS := $(shell pkg-config opencv --libs)
FLAG := $(shell pkg-config opencv --cflags)
FLAG += -g

OUT := leaf
SRC := main.cpp svm.cpp classifier.cpp

all:
	g++ $(FLAG) $(SRC) -o $(OUT) $(LIBS)
