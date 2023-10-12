# CXX=/home/boo/compilers/ekopath-4.0.12.1/bin/pathCC
# CXXOPTIMIZE=-Ofast -OPT:alias=restrict
# CXXFLAGS=-Drestrict= $(CXXOPTIMIZE)

# CXX=/home/boo/compilers/open64-5.0-build/bin/openCC
# # CXXOPTIMIZE=-Ofast
# CXXOPTIMIZE=-Ofast -fb-create fbout
# # CXXOPTIMIZE=-Ofast -fb-opt fbout
# CXXFLAGS=-Wall -Werror -Drestrict= $(CXXOPTIMIZE)

# CXX=clang++-6.0
# CXXOPTIMIZE=-O3 -ffast-math
# CXXFLAGS=-Wall -Werror -Drestrict= $(CXXOPTIMIZE)

CXX = g++
CXXOPTIMIZE=-Ofast
# CXXOPTIMIZE=-Ofast -flto -fprofile-generate
# CXXOPTIMIZE=-Ofast -flto -fprofile-use
CXXFLAGS=-Wall -Werror -Drestrict= $(CXXOPTIMIZE)

# CXX = /home/boo/compilers/enzo-4.9.01/bin/pathCC
# CXXOPTIMIZE=-Ofast
# # CXXOPTIMIZE=-Ofast -fb-create fbout
# # CXXOPTIMIZE=-Ofast -fb-opt fbout
# CXXFLAGS=-Wall -Werror -Drestrict= $(CXXOPTIMIZE)

# CXX = icpc
# CXXFLAGS= -restrict -fast
# # CXXFLAGS= -restrict -fast -ipo -prof-gen
# # CXXFLAGS= -restrict -fast -ipo -prof-use

# CXX = /home/boo/programs/numerics/FTensor/pgi/linux86-64/17.10/bin/pgc++
# # CXXFLAGS = -fast -Mipa=fast,inline --restrict
# CXXFLAGS = -std=c++14 -fast -Mipa=fast,inline --restrict -I/usr/include/x86_64-linux-gnu


% :: %,v

all: little littlefast example examplefast bench
# all: little littlefast example examplefast speed_test one_over one_over_fast

BENCH_SRCS=bench.cpp tensor1.cpp tensor3.cpp tensor5.cpp tensor7.cpp tensor2.cpp tensor4.cpp tensor6.cpp tensor8.cpp tensor9.cpp ctran1.cpp ctran2.cpp ctran3.cpp ctran4.cpp ctran5.cpp ctran6.cpp ctran7.cpp ctran8.cpp ctran9.cpp
BENCH_OBJS=$(subst .cpp,.o,$(BENCH_SRCS))

bench: $(BENCH_OBJS)
	$(CXX) $(BENCH_OBJS) $(CXXFLAGS) -o bench

algebra3: algebra3_test1 algebra3_test2 algebra3_test3 algebra3_test4 algebra3_test5 algebra3_test6 algebra3_test7 algebra3_test8 algebra3_test9


clean:
	rm -f *.o bench little littlefast example examplefast speed_test algebra3_test1 algebra3_test2 algebra3_test3 algebra3_test4 algebra3_test5 algebra3_test6 algebra3_test7 algebra3_test8 algebra3_test9
