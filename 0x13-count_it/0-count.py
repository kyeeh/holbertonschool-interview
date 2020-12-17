#!/usr/bin/python3
"""
0x13. Count it!
"""
import requests
import sys


def count_words(subreddit, word_list, kw_cont={}, next_pg=None, reap_kw={}):
    """
    Parses the title of all hot articles, and prints a sorted count of given
    keywords
    """
    headers = {"User-Agent": "kyeeh"}

    if next_pg:
        srdt = requests.get('https://reddit.com/r/' + subreddit +
                            '/hot.json?after=' + next_pg, headers=headers)
    else:
        srdt = requests.get('https://reddit.com/r/' + subreddit +
                            '/hot.json', headers=headers)

    if srdt.status_code == 404:
        return

    if kw_cont == {}:
        for word in word_list:
            kw_cont[word] = 0
            reap_kw[word] = word_list.count(word)

    srdt_dict = srdt.json()
    srdt_data = srdt_dict['data']
    srdt_psts = srdt_data['children']
    next_pg = srdt_data['after']

    for post in srdt_psts:
        post_data = post['data']
        post_title = post_data['title']
        title_words = post_title.split()
        for w in title_words:
            for key in kw_cont:
                if w.lower() == key.lower():
                    kw_cont[key] += 1

    if next_pg:
        count_words(subreddit, word_list, kw_cont, next_pg, reap_kw)
    else:
        for key, val in reap_kw.items():
            if val > 1:
                kw_cont[key] *= val

        srtd_abc = sorted(kw_cont.items(), key=lambda x: x[0])
        srtd_res = sorted(srtd_abc, key=lambda x: (-x[1], x[0]))
        for res in srtd_res:
            if res[1] > 0:
                print('{}: {}'.format(res[0], res[1]))
