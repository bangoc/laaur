package main
import (
	"fmt"
	"math"
)

type point struct {
	x, y float64
}

func (p1 point) distance(p2 point) float64 {
	dx := p1.x - p2.x
	dy := p1.y - p2.y
	return math.Sqrt(dx * dx + dy * dy)
}

func (p point) scale(k float64) {
	p.x *= k
	p.y *= k
}

func main() {
	var p1, p2 point
	fmt.Scanf("%f%f%f%f", &p1.x, &p1.y,
		&p2.x, &p2.y)
	fmt.Printf("%f\n", p1.distance(p2))
}