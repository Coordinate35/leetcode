package main

import "strconv"

type stack struct {
	elem []int
}

func newStack() *stack {
	return &stack{}
}

func (s *stack) push(e int) {
	s.elem = append(s.elem, e)
}

func (s *stack) pop() int {
	count := len(s.elem)
	e := s.elem[count-1]
	s.elem = s.elem[:count-1]

	return e
}

func plus(s *stack) {
	a := s.pop()
	b := s.pop()
	s.push(b + a)
}

func minus(s *stack) {
	a := s.pop()
	b := s.pop()
	s.push(b - a)
}

func multiply(s *stack) {
	a := s.pop()
	b := s.pop()
	s.push(b * a)
}

func division(s *stack) {
	a := s.pop()
	b := s.pop()
	s.push(b / a)
}

func evalRPN(tokens []string) int {

	operator := map[string]func(s *stack){
		"+": plus,
		"-": minus,
		"*": multiply,
		"/": division,
	}

	s := newStack()
	for i := range tokens {
		token := tokens[i]
		if handler, exist := operator[token]; exist {
			handler(s)
		} else {
			number, err := strconv.Atoi(token)
			if err != nil {
				return 0
			}
			s.push(number)
		}
	}

	return s.pop()
}
