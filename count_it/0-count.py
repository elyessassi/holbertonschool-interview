#!/usr/bin/python3

import requests


def count_words(subreddit, word_list):

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    response = requests.get(url, allow_redirects=False)
    if (response.status_code != 200):
        return
    articles = response.json()["data"]["children"]
    title_list = get_titles(articles, 0, [])
    # word_dict = turn_into_dict\(word_list, 0, {})
    word_count = []
    # turning elements to lowercase and remove duplicates
    word_list = turn_list_lower(word_list, 0)

    word_list = list(set(word_list))
    # createing list with zeros
    word_count = filling_list_zero(word_list, 0, word_count)
    word_count = compare_lists(word_list, word_count, 0, title_list)
    word_dict = turn_to_sorted_dict(word_list, word_count, {})
    print_dict(list(word_dict.keys()), list(word_dict.values()), 0)

# this function is used to fill word_count with zeros


def filling_list_zero(word_list, index, word_count):

    if (index >= len(word_list)):
        return (word_count)
    word_count.append(0)
    return filling_list_zero(word_list, index + 1, word_count)


def turn_list_lower(thelist, index):

    if (index >= len(thelist)):
        return (thelist)
    thelist[index] = thelist[index].lower()
    return turn_list_lower(thelist, index + 1)


def get_titles(articlesList, index, titleList):

    if (index >= len(articlesList)):
        return (titleList)
    title = articlesList[index]["data"]["title"].split()
    title = turn_list_lower(title, 0)
    titleList.extend(title)
    return get_titles(articlesList, index + 1, titleList)


def compare_lists(word_list, word_count, index, title_list):

    if (index >= len(word_list)):
        return (word_count)
    word_count[index] = word_count[index] + title_list.count(word_list[index])
    return compare_lists(word_list, word_count, index + 1, title_list)


def turn_to_sorted_dict(word_list, word_count, dictionnary):

    if (word_list == []):
        return (dictionnary)
    indexMax = word_count.index(max(word_count))
    dictionnary[word_list[indexMax]] = word_count[indexMax]
    word_list.pop(indexMax)
    word_count.pop(indexMax)
    return turn_to_sorted_dict(word_list, word_count, dictionnary)


def print_dict(keys_list, values_list, index):

    if (index >= len(keys_list)):
        return
    if (values_list[index] != 0):
        print(f"{keys_list[index]}: {values_list[index]}")
        print_dict(keys_list, values_list, index + 1)
