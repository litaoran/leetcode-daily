func min(x,y int) int {
    if x<y {
        return x
    } else {
        return y
    }
}

func minAvailableDuration(slots1 [][]int, slots2 [][]int, duration int) []int {
    
    sort.Slice(slots1, func(i,j int) bool {
        return slots1[i][0] < slots1[j][0]
        } )
    sort.Slice(slots2, func(i,j int) bool {
        return slots2[i][0] < slots2[j][0]
    } )
    
    i:=0
    j:=0
    
    for i<len(slots1) && j<len(slots2) {
        if (slots1[i][0] < slots2[j][0]) {
            if slots2[j][0]+duration<= min(slots1[i][1], slots2[j][1]) {
                return []int{slots2[j][0], slots2[j][0]+duration}
            }
            if (slots1[i][1] < slots2[j][1]) {
                i++
            } else {
                j++
            }     
        } else {
            if slots1[i][0]+duration<= min(slots1[i][1], slots2[j][1]) {
                return []int{slots1[i][0], slots1[i][0]+duration}
            }
            if (slots1[i][1] < slots2[j][1]) {
                i++
            } else {
                j++
            }
        }
        
    }
    return []int{}
}
