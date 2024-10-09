target = app
src = $(wildcard *.cpp ./src/*.cpp)
obj = $(patsubst %.cpp, %.o, $(src))
include = ./include

$(target): $(obj)
	g++ -o $@ $^  # 这里的 ^ 应该是 $^

%.o: %.cpp
	g++ -c $< -I $(include) -o $@ -lpthread  # -c 选项应放在 $< 之前

.PHONY: clean

clean:
	-rm -f $(obj) $(target)  # -f 选项应放在 rm 命令之前

