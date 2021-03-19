func findMinArrowShots(points [][]int) int {
    if len(points) <=1 {return len(points) }
    
    sort.Slice(points, func(i,j int) bool {return points[i][1] < points[j][1] }  ); 
    
    i := 1
    cur_max := points[0][1]
    cnt := 1
    for i< len(points) {
        if points[i][0] <= cur_max {
        } else {
            cnt++
            cur_max = points[i][1]
        }
        i++
    } 
    
    return cnt
}
