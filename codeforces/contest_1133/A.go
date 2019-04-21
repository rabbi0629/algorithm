package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type IoReader struct {
	scanner *bufio.Scanner
}

func NewIoReader() *IoReader {
	r := new(IoReader)
	r.scanner = bufio.NewScanner(os.Stdin)
	r.scanner.Split(bufio.ScanWords)
	return r
}

func (r *IoReader) ReadString() string {
	r.scanner.Scan()
	return r.scanner.Text()
}

func (r *IoReader) ReadInt64() int64 {
	r.scanner.Scan()
	i, _ := strconv.ParseInt(r.scanner.Text(), 10, 64)
	return i
}

func (r *IoReader) ReadFloat64() float64 {
	r.scanner.Scan()
	i, _ := strconv.ParseFloat(r.scanner.Text(), 10)
	return i
}

func main() {
	reader := NewIoReader()
	a := reader.ReadInt64()
	b := reader.ReadInt64()
	fmt.Println(a + b)
}
