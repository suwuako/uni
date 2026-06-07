CXX = clang++ CPPFLAGS = -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op \
           -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 \
           -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector \
           -O2 --std=c++23 -g 

asan:
	clang++ -Wall -g -fsanitize=address,undefined sol.cpp
msan:
    clang++ -Wall -g -fsanitize=memory,undefined -fsanitize-memory-track-origins sol.cpp
clean:
	rm a.out

all:
	${CXX} ${CPPFLAGS} sol.cpp
