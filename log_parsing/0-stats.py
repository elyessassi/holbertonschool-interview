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
    regex = '\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}\s-\s\[\d{4}-\d{1,2}-\d{1,2}\s\d{1,2}:\d{1,2}:\d{1,2}\.\d{6}\]\s"\w{3}\s\/projects\/260\sHTTP\/1.1"\s\d{3}\s\d{1,4}'
    for line in stdin:
        if re.findall(regex, line) == []:
            continue
        else:
            num_lines += 1
            files_size += int((re.findall(file_size_regex, line))[0])
            error = (re.search(error_regex, line))[0]
            error_dict[error] += 1
            if num_lines == 10:
                print(f"File size: {files_size}")
                for i in error_dict:
                    if error_dict[i] != 0:
                        print(f"{i}: {error_dict[i]}")
                files_size = 0
                num_lines = 0
                error_dict = {"200":0, "301":0, "400":0, "401":0, "403":0, "404":0, "405":0, "500":0}

if __name__=="__main__":
    main()