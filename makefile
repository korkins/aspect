MAINDIR = ./

SRCDIR = src_c

install: build
	@echo $(MAINDIR)
	mv $(SRCDIR)/*.exe $(MAINDIR)

build:
	$(MAKE) -C $(SRCDIR)

clean:
	rm $(SRCDIR)/*.o