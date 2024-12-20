target = serve1
src = $(wildcard *.cpp) $(wildcard ./src/*.cpp)   
obj = $(patsubst %.cpp, %.o, $(src))
include = ./include
LIBS = -lsqlite3

$(target): $(obj)
	g++ -o $@ $^ $(LIBS)  # Link libraries here

%.o: %.cpp
	g++ -c $< -I $(include) -o $@   

.PHONY: clean

clean:
	-rm -f $(obj) $(target)
