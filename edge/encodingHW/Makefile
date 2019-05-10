TARGET = encoder
CFLAGS = -Wall -g
OBJS = main.o encoder.o gpio.o
LIBS = 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS)

clean: 
	rm -f $(OBJS) $(TARGET)
