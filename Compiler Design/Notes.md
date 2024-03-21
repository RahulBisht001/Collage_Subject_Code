* Every Lex Program contains 3 sections

  1. Definitions Section (%%):

        This section contains declarations of regular expressions along with the corresponding action to be taken when a pattern is matched. Each definition consists of a regular expression followed by an action.

  2. Rules Section:

        This part defines the rules for recognizing patterns. It consists of a set of rules where each rule specifies a pattern to be matched and the corresponding action to be taken when the pattern is found.

  3. Code Section:

        This section contains any additional C code that you want to include in your Lex program. This code is copied verbatim into the generated C file and can be used to define functions or include header files, among other things. This section is typically enclosed within %%{ and %%} delimiters.


* Definition section opens with `%` followed by `{` and ends with `%` followed by `}`.
* Rules section opesn with `%%` and ends with `%%`.