#!/usr/bin/env python3

import argparse
import os

def read_file(filename: str) -> list:
    with open(filename, "r") as f:
        return f.readlines()

def write_file(filename: str, content: "list[str]"):
    with open(filename, "w") as f:
        f.writelines(content) 

def is_header(text: str) -> bool:
    return text.startswith("### ")

def parse_header(text: str) -> str:
    id = text.find("[")
    if id != -1:
        return text[id+1:text.rfind("]")]
    return text[4:-1]

def make_header(text: str) -> str:
    return f"### [{text}]({text})\n"

def get_headers(readme: "list[str]") -> "list[str]":
    headers = []
    for line in readme:
        if is_header(line):
            headers.append(parse_header(line))
    return sorted(headers)

def get_unique_from_b(a,b):
    a = set(a)
    b = set(b)
    return b - a


def get_updated_readme(old_readme: "list[str]", new_examples: "list[str]") -> "list[str]":
    output = []
    new_examples = sorted(new_examples)
    for line in old_readme:
        if is_header(line):
            header = parse_header(line)
            while len(new_examples) != 0 and new_examples[0] < header:
                output.append(make_header(new_examples[0]))
                del new_examples[0]
        output.append(line)
    for example in new_examples:
        output.append(make_header(example))
    return output

def main(args):
    dirs = [file for file in os.listdir(args.workspace) if os.path.isdir(file) and not file.startswith(".")] 
    dirs.sort()
    readme = read_file(args.readme)
    new_examples = get_unique_from_b(get_headers(readme), dirs)
    readme = get_updated_readme(readme, new_examples)
    write_file("readme.md", readme)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="This script checks available directories and inserts them into readme in alphabetical order with appropriate links and description section")
    parser.add_argument("readme", help="Current readme file")
    parser.add_argument("workspace", help="Directory which contains all examples")
    args = parser.parse_args()
    main(args)
