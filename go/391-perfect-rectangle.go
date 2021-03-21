import (
    "math"
)

func min(x,y int) int {
    if x<y { return x
    } else {
        return y
    }
}

func max(x,y int) int {
    if x>y {return x
    } else { return y }    
}


func isRectangleCover(rectangles [][]int) bool {
    m := make(map[int]map[int]int)
    
    xmin := math.MaxUint32
    xmax := 0
    ymin := math.MaxUint32
    ymax := 0
    area := 0
    for _, rec := range rectangles {
        xmin = min(xmin, rec[0])
        xmax = max(xmax, rec[2])
        ymin = min(ymin, rec[1])
        ymax = max(ymax, rec[3])
        
        area += (rec[2]-rec[0]) * (rec[3] - rec[1])
        if _,ok :=  m[rec[0]]; !ok {
            m[rec[0]] = make(map[int]int)
        }
        if _,ok :=  m[rec[2]]; !ok {
            m[rec[2]] = make(map[int]int)
        }
        m[rec[0]][rec[1]]++
        m[rec[0]][rec[3]]++
        m[rec[2]][rec[3]]++
        m[rec[2]][rec[1]]++
    }
    
    if area != ((xmax-xmin)*(ymax-ymin)) {
        return false
    }
    
    for x,_ := range m {
        for y,v := range m[x] {
            if (x==xmin || x==xmax) && (y==ymin || y==ymax) {
                if v!=1 {
                    return false
                }
            } else {
                if v%2!=0 {
                    return false
                }                
            }
        }
    }
    
    return true
}
