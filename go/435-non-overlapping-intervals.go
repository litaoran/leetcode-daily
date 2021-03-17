func eraseOverlapIntervals(intervals [][]int) int {
    if len(intervals)==0 {return 0}
    
    sort.Slice(intervals, func(i,j int) bool{ return intervals[i][0] < intervals[j][0]; } )
    cnt := 0
    
    cur_max := intervals[0][1] 
    i :=1
    for i<len(intervals) {
        s := intervals[i][0]
        e := intervals[i][1]
        
        if cur_max > s {
            cnt++
            if e < cur_max {
                cur_max = e
            }
        } else {
            cur_max = e
        }
                
        i++
    }
    
    return cnt;
}
