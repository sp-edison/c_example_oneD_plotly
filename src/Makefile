TARGET	= Sin.x

CC	= gcc
CFLAGS	= 
LINKER 	= gcc
LFLAGS	= -lm

BINDIR	= ../bin

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

.SUFFIXES : .c .o

all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(BINDIR) $(OBJS)
	$(LINKER) $(LFLAGS) -o $@ $(OBJS)
	@echo "Linking complete!"

$(OBJS): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

$(BINDIR):
	mkdir $(BINDIR)

clean:
	rm -rf $(OBJS) $(BINDIR)/$(TARGET)
