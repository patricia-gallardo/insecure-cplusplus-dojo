
lambda { |stdout,stderr,status|
  output = stdout + stderr
  return :red   if /assertions: \d+ | \d+ failed/.match(output)
  return :red   if /assertions: \d+ | \d+ passed | \d+ failed/.match(output)
  return :red   if /failed \(\d+ assertion/.match(output)
  return :green if /All tests passed/.match(output)
  return :amber
}
