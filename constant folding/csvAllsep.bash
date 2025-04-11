echo -n "T | Opt-O0 | Unopt-O0 | Opt-O2 | Unopt-O2"

echo ""
echo -n "1"
cd testcase1
bash csvOutputc.bash
echo ""
echo -n "1G"
bash csvOutputg.bash
cd ..
echo ""
echo -n "2"
cd testcase2
bash csvOutputc.bash
echo ""
echo -n "2G"
bash csvOutputg.bash
cd ..
echo ""
echo -n "3"
cd testcase3
bash csvOutputc.bash
echo ""
echo -n "3G"
bash csvOutputg.bash
cd ..