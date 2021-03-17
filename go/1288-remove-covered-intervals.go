func removeCoveredIntervals(intervals [][]int) int {
    total := len(intervals)
    if total <= 1 {return total}
    
    
    sort.Slice(intervals, func(i,j int) bool {
        if intervals[i][0] != intervals[j][0] {
            return intervals[i][0] < intervals[j][0]
        } else {
            return intervals[i][1] > intervals[j][1]
        } })
    
    cur_max := intervals[0][1]
    i := 1
    for (i < len(intervals)) {    
        e := intervals[i][1]
        
        if (cur_max >= e) {
            total--
        } else {
            cur_max = e
        }
        i++
    }
    
    
    return total
}
