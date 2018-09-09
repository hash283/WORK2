# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

It is a synonym for a lung disease caused by dust and ash particulates.

## According to its man page, what does `getrusage` do?

TODO

## Per that same man page, how many members are in a variable of type `struct rusage`?

TODO

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

TODO

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

TODO

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

fscanf requires format specifiers unlike fgetc,moreover it requires to know the exact no of words in a sentence to read it correctly.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

TODO
