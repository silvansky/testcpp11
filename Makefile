CC=clang
OPTS=-Wall -pedantic -std=c++0x -stdlib=libc++
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

TARGET=testcpp11

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

.cpp.o:
	$(CC) -c $(OPTS) $<

clean:
	rm $(TARGET) $(OBJECTS)

