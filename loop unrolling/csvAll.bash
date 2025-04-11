echo -n "T|Opt-O0|Unopt-O0|Opt-O0-GCC|Unopt-O0-GCC|Opt-O2|Unopt-O2|Opt-O2-GCC|Unopt-O2-GCC"

echo ""
echo -n "1"
cd testcase1
bash csvOutput.bash
cd ..
echo ""
echo -n "2"
cd testcase2
bash csvOutput.bash
cd ..