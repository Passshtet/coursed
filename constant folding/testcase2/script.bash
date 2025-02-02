RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

echo "O0"
clang++ -O0 -std=c++14 -Wno-everything -o optimized optimized.cpp
clang++ -O0 -std=c++14 -Wno-everything -o unoptimized unoptimized.cpp
g++ -O0 -std=c++14 -Wno-everything -o optimizedg optimized.cpp
g++ -O0 -std=c++14 -Wno-everything -o unoptimizedg unoptimized.cpp

echo "clang:"
./optimized
cp trash.txt checktrash.txt
echo -e "${YELLOW}Reference${NC}"
./unoptimized
if cmp -s trash.txt checktrash.txt; then
    echo -e "${GREEN}No difference${NC}"
else
    echo -e "${RED}Difference${NC}"
fi

echo "gcc:"
./optimizedg
if cmp -s trash.txt checktrash.txt; then
    echo -e "${GREEN}No difference${NC}"
else
    echo -e "${RED}Difference${NC}"
fi
./unoptimizedg
if cmp -s trash.txt checktrash.txt; then
    echo -e "${GREEN}No difference${NC}"
else
    echo -e "${RED}Difference${NC}"
fi

echo "O1"
clang++ -O1 -std=c++14 -Wno-everything -o optimized optimized.cpp
clang++ -O1 -std=c++14 -Wno-everything -o unoptimized unoptimized.cpp
g++ -O1 -std=c++14 -Wno-everything -o optimizedg optimized.cpp
g++ -O1 -std=c++14 -Wno-everything -o unoptimizedg unoptimized.cpp

echo "clang:"
./optimized
if cmp -s trash.txt checktrash.txt; then
    echo -e "${GREEN}No difference${NC}"
else
    echo -e "${RED}Difference${NC}"
fi
./unoptimized
if cmp -s trash.txt checktrash.txt; then
    echo -e "${GREEN}No difference${NC}"
else
    echo -e "${RED}Difference${NC}"
fi

echo "gcc:"
./optimizedg
if cmp -s trash.txt checktrash.txt; then
    echo -e "${GREEN}No difference${NC}"
else
    echo -e "${RED}Difference${NC}"
fi
./unoptimizedg
if cmp -s trash.txt checktrash.txt; then
    echo -e "${GREEN}No difference${NC}"
else
    echo -e "${RED}Difference${NC}"
fi

echo "O2"
clang++ -O2 -std=c++14 -Wno-everything -o optimized optimized.cpp
clang++ -O2 -std=c++14 -Wno-everything -o unoptimized unoptimized.cpp
g++ -O2 -std=c++14 -Wno-everything -o optimizedg optimized.cpp
g++ -O2 -std=c++14 -Wno-everything -o unoptimizedg unoptimized.cpp

echo "clang:"
./optimized
if cmp -s trash.txt checktrash.txt; then
    echo -e "${GREEN}No difference${NC}"
else
    echo -e "${RED}Difference${NC}"
fi
./unoptimized
if cmp -s trash.txt checktrash.txt; then
    echo -e "${GREEN}No difference${NC}"
else
    echo -e "${RED}Difference${NC}"
fi

echo "gcc:"
./optimizedg
if cmp -s trash.txt checktrash.txt; then
    echo -e "${GREEN}No difference${NC}"
else
    echo -e "${RED}Difference${NC}"
fi
./unoptimizedg
if cmp -s trash.txt checktrash.txt; then
    echo -e "${GREEN}No difference${NC}"
else
    echo -e "${RED}Difference${NC}"
fi

echo "O3"
clang++ -O3 -std=c++14 -Wno-everything -o optimized optimized.cpp
clang++ -O3 -std=c++14 -Wno-everything -o unoptimized unoptimized.cpp
g++ -O3 -std=c++14 -Wno-everything -o optimizedg optimized.cpp
g++ -O3 -std=c++14 -Wno-everything -o unoptimizedg unoptimized.cpp

echo "clang:"
./optimized
if cmp -s trash.txt checktrash.txt; then
    echo -e "${GREEN}No difference${NC}"
else
    echo -e "${RED}Difference${NC}"
fi
./unoptimized
if cmp -s trash.txt checktrash.txt; then
    echo -e "${GREEN}No difference${NC}"
else
    echo -e "${RED}Difference${NC}"
fi

echo "gcc:"
./optimizedg
if cmp -s trash.txt checktrash.txt; then
    echo -e "${GREEN}No difference${NC}"
else
    echo -e "${RED}Difference${NC}"
fi
./unoptimizedg
if cmp -s trash.txt checktrash.txt; then
    echo -e "${GREEN}No difference${NC}"
else
    echo -e "${RED}Difference${NC}"
fi