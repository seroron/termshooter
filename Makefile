.SUFFIXES:
.SUFFIXES: .o .cpp .h .d

CXX      := g++
RM       := rm
SED      := sed
MV	 := mv

TARGET   := termshooter
LIBRARY  := -lncurses
CXXFLAGS := -std=c++1y -I/usr/include/ncurses -Wall -Wextra -Wno-unused-parameter -O2 

SRC_DIR  += src
SRC      += $(foreach dir,$(SRC_DIR), $(wildcard $(dir)/*.cpp)) 
OBJECT   := $(subst .cpp,.o,$(filter %.cpp,$(SRC)))
DEP_FILE := $(OBJECT:.o=.d)

.PHONY : all
all: $(TARGET)

$(TARGET): $(OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECT) $(LIBRARY)

.PHONY : clean
clean:
	-$(RM) -fr $(TARGET) $(OBJECT) $(DEP_FILE)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.d: %.c


ifneq "$(MAKECMDGOALS)" "clean"
-include $(DEP_FILE)
endif

.cpp.d:
	$(CXX) $(CXXFLAGS) -MM $< | \
	$(SED) 's,\($(notdir $*)\.o\) *:,$(dir $@)\1 $@: ,' >$@.tmp
	$(MV) $@.tmp $@
