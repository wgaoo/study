#coding = "utf-8"

from django.shortcuts import render
from django.http import HttpResponse
import sys

def index(request):
    return HttpResponse("index of studyhtml")

def test(request):
    alltext = open("./studyhtml/htmls/test.html", 'r+').read()
    return HttpResponse(alltext)
