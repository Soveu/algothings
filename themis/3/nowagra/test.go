package main

import(
  "fmt"
  "os/exec"
)

func main() {
  program := exec.Command("./a.out")
  prog_in, err := cmd.StdinPipe()

  if err != nil {
    fmt.Println(err)
  }

}

