SUBDIRS := $(wildcard questao*/.)

all: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@
.PHONY: $(TOPTARGETS) $(SUBDIRS)