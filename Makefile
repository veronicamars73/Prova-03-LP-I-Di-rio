PROG = diary
CC = g++
CPPFLAGS = -O0 -std=c++11 -g 
OBJS = main.o Message.o Date.o Time.o Diary.o App.o Helpers.o Configuration.o Interactive.o

all: $(PROG)

$(PROG) : $(OBJS)
	$(CC)  $(OBJS)  -o $(PROG)

main.o :
	$(CC) $(CPPFLAGS) -c src/main.cpp

Configuration.o :  include/Configuration.h
	$(CC) $(CPPFLAGS) -c src/Configuration.cpp

Interactive.o :  include/Interactive.h
	$(CC) $(CPPFLAGS) -c src/Interactive.cpp

Message.o : include/Message.h
	$(CC) $(CPPFLAGS) -c src/Message.cpp

Date.o :  include/Date.h
	$(CC) $(CPPFLAGS) -c src/Date.cpp

Time.o :  include/Time.h
	$(CC) $(CPPFLAGS) -c src/Time.cpp

Helpers.o :  include/Helpers.h
	$(CC) $(CPPFLAGS) -c src/Helpers.cpp

Diary.o :  include/Diary.h
	$(CC) $(CPPFLAGS) -c src/Diary.cpp

App.o :  include/App.h
	$(CC) $(CPPFLAGS) -c src/App.cpp

clean:
	rm -f *.o
	rm $(PROG)
