import os
import argparse
import time
import string


def load_dict(path_dict: str):
    """
    @arguments:
        - path_dict (string): the path of dictionary/syllabus file.
    @return values:
        - A list of word in dictionary file 
    """

    with open(path_dict, 'r', encoding="utf8") as f:
        content = f.read()
        word_list = content.splitlines()
        return word_list
    return []


def load_test(path_test:str):
    """
    @arguments:
        - path_test (string): the path of test document containt some of paragraph we need check.
    @return values:
        - the dictionary contain all word in test document and the frequency of them. 
    """
    with open(path_test, 'r', encoding="utf8") as f:
        content = f.read()
        word_list = list(map(str, content.split(" ")))
    
        # make a table for preprocess data
        table = str.maketrans('', '', string.punctuation)

        # Count the frequency of every word in the test file.
        dict_count = dict()
        
        for word in word_list:
            # preprocess data
            word = word.translate(table).upper()
            if " " not in word and "\n" not in word:
                if word in dict_count:
                    # increase frequency of word
                    dict_count[word] += 1
                else:
                    # add the word to dictionary
                    dict_count[word] = 1
        return dict_count

    return None

def display_test(document: dict):
    for item in document:
        print(item, end="   ")
        print(document[item])
    
def display_dict(dictionary: list):
    for item in dictionary:
        print(item)
    
    
def process(dictionary: list, document: dict):
    """
    @parameter:
        dictionary:
        documents:
    @return values:
        - A dictionary that the key value is the word in the dictionary and the value is the frequency of word appear
        in the documents.

    """
    # Solve the question a: count the number of word in the dictionary exist in documents.
    count_appear = 0
    for word in dictionary:
        if word in document:
            count_appear += 1

    # Solve the question b: calculate the frequency.
    frequency = count_appear / len(dictionary) * 100

    return count_appear, frequency


def main(args):
    path_dictionary = args.dict_path
    path_test_file = args.test_path
    dictionary = load_dict(path_dict=path_dictionary)
    document = load_test(path_test=path_test_file)

    # print("-------------------------The dictionary---------------------------")
    # display_dict(dictionary=dictionary)
    # print("-------------------------The test document------------------------")
    # display_test(document=document)

    # Solve problem
    count_appear, frequency = process(dictionary=dictionary, document=document)
    print(f"The number of word in dictionary appear in the test document is {count_appear}")
    print(f"The percentage is {frequency} %")
    


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Count the frequency of the words in dictionary appear in test file.')
    parser.add_argument("--dict_path", help="The path of dictionary", default="syllables.txt")
    parser.add_argument("--test_path", help="The path of test file.", default="test.txt")
    args = parser.parse_args()
    START_TIME = time.time()
    main(args)
    print("The time execution is  %s seconds ---" % (time.time() - START_TIME))
  
