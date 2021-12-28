package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

var wg sync.WaitGroup

func player(name string, table chan int) {
	defer wg.Done()
	for {
		ball := <-table
		if ball == 0 {  // Đối phương đánh trượt bóng
			fmt.Println("Điểm cho ", name)
			break
		}
		fmt.Println(ball, " => ", name)  // Đối phương đánh trúng, bóng đi tới
		time.Sleep(100 * time.Millisecond)
		if rand.Int() % 61 == 0 {
			fmt.Println(name, " Đánh trượt")
			table <- 0  // Đánh trượt bóng
			break
		}
		ball++  // Đánh trúng bóng
		table <- ball  // Gửi bóng cho đối phương
	}
}

func main() {
	rand.Seed(time.Now().UnixNano())
	table := make(chan int)
	wg.Add(2)
	go player("ping", table)
	go player("pong", table)
	table <- 1  // Giao bóng
	wg.Wait()
}