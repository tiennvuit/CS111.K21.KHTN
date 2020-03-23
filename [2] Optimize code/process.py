import os
import argparse


def load(path_file):
    """

    """
    pass


def process(dictionary: dict, documents):
    """
    @parameter:
        dictionary:
        documents:
    @return values:
        - A dictionary that the key value is the word in the dictionary and the value is the frequency of word appear in the documents.

    """
    return {}

def display(result: dict):
    """
    Display the frequency of every word appear in the documents (don't display the word not exist in the documents)
    """
    for key, value in result.items():
        print(key, "*"*10, value)

    # Some conclusin


def main(args):
    path_dictionary = args.dict_path
    path_test_file = args.test_path
    dictionary = load(path_dictionary)
    documents = load(path_test_file)

    result = process(dictionary=dictionary, documents=documents)
    display(result=result)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Count the frequency of the words in dictionary appear in test file.')
    parser.add_argument("dict_path",  help="The path of dictionary", default="./syllables.txt")
    parser.add_argument("test_path", help="The path of test file.", default="./test.txt")
    args = parser.parse_args()
    print(args)

    main(args)
