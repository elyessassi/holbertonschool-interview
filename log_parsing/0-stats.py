#!/usr/bin/python3

""" 
    log parsing algorithm that takes logs from an other file
    and shows the file size and the number of appearence of each
    type of error
"""

from sys import stdin
import re



def main():
    """ Main function """
    error_dict = {"200":0, "301":0, "400":0, "401":0, "403":0, "404":0, "405":0, "500":0}
    num_lines = 0
    files_size = 0
    file_size_regex = '\d{1,4}$'
    error_regex = '(?<=\d"\s)\d{3}'
    regex = '.*\s?-\s?\[\d{4}-\d{1,2}-\d{1,2}\s\d{1,2}:\d{1,2}:\d{1,2}\.\d{6}\]\s"\w{3}\s\/projects\/260\sHTTP\/1.1"\s\d{3}\s\d{1,4}'
    data = stdin.read()
    if data == "":
        print(f"File size: {files_size}")
    lines = data.splitlines()
    try:
        for i in range(len(lines)):
            if re.findall(regex, lines[i]) == []:
                print(f"this is the data {data}  end of data")
                continue
            else:
                num_lines += 1
                files_size += int((re.findall(file_size_regex, lines[i]))[0])
                error = (re.search(error_regex, lines[i]))[0]
                error_dict[error] += 1
                if num_lines == 10:
                    print(f"File size: {files_size}")
                    for i in error_dict:
                        if error_dict[i] != 0:
                            print(f"{i}: {error_dict[i]}")
                    num_lines = 0
        if num_lines != 0 and i == len(lines) - 1:
            print(f"File size: {files_size}")
            for i in error_dict:
                if error_dict[i] != 0:
                    print(f"{i}: {error_dict[i]}")
    except KeyboardInterrupt: 
        print(f"File size: {files_size}")
        for i in error_dict:
            if error_dict[i] != 0:
                print(f"{i}: {error_dict[i]}")


if __name__=="__main__":
    main()