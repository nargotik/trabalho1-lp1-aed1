SUBDIRS := $(wildcard questao*/.)

all: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@
clean:
	rm bin/questao*
.PHONY: $(TOPTARGETS) $(SUBDIRS)
