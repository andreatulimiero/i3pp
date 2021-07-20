#!/bin/bash
find . -name '*.c' | xargs -I_ mv _ _pp
find . -name '*.h' | xargs -I_ mv _ _pp

find . -name "*.hpp" | xargs -I_ sed 's/#include "\(.*\).h"/#include "\1.hpp"/' -i _
find . -name "*.cpp" | xargs -I_ sed 's/#include "\(.*\).h"/#include "\1.hpp"/' -i _

find . -name "*.cpp" | xargs -I_ sed 's/#include <config.h>/#include <config.hpp>/' -i _
find . -name "*.hpp" | xargs -I_ sed 's/#include <config.h>/#include <config.hpp>/' -i _
