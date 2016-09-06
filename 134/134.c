/**
 * 由于题目保证如果有解的话，就肯定有唯一解。于是从第一个元素开始，若果走到某个地方走不下去了
 * 那必然从中间的某个点都走不到那个点。于是中间的点都不可能是解。所以就再次从走不下去的那个点
 * 开始走。由于并没有模拟从每一个点开始的情况，所以即使最后得出一个一个数，没有再检查他之前的
 * 数是否能完成，所以就要鉴别这个是不是真的解。如果所有站点的油量和大于要消耗的油亮和，则必然
 * 有真解，用这个来判断
 */

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int current_sum = 0;
    int total = 0;
    int i;
    int last_end = -1;
    for (i = 0; i < gasSize; i++) {
        current_sum += gas[i] - cost[i];
        total += gas[i] - cost[i];
        if (0 > current_sum) {
            last_end = i;
            current_sum = 0;
        }
    }
    return total >= 0 ? last_end + 1 : -1;
}