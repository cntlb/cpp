CPP = g++
OFLAG = -o
OUTDIR = ./bin/

#后缀规则
.SUFFIXES: .o .cpp .c
.cpp.o:#.cpp -> .o 使用-c编译选项
	$(CPP) $(CPPFLAGS) -c $<
.c.o:
	$(CPP) $(CPPFLAGS) -c $<
#all依赖hello1 hello2,并且all不存在的情况下创建hello1 hello2
all: hello1 hello2
hello1:hello1.o
	$(CPP) $(OFLAG) $(OUTDIR)hello1 hello1.o
hello2:hello2.o
	$(CPP) $(OFLAG) $(OUTDIR)hello2 hello2.o

hello1.o:hello1.cpp
hello2.o:hello2.c
