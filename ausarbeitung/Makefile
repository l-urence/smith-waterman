OBJ = $(shell find . -name "*.tex")
DOCUMENT = psys_dna
TEXT_FILE = psys_dna_text

.PHONY : clean open bib, publish
.SILENT: all

all: $(DOCUMENT).pdf

open: all
	@open $(DOCUMENT).pdf

$(TEXT_FILE).tex: $(TEXT_FILE).md
	@echo "Generate tex file out of markdown"
	@pandoc -o $(TEXT_FILE).tex $(TEXT_FILE).md
	@for S in `grep -E "\includegraphics{.*}" $(TEXT_FILE).tex`; do \
		F=$$(expr "$$S" : '\\includegraphics{\(.*\)}' | sed 's/\//\\\//g'); \
		sed -i.bak "s/\\includegraphics{$$F}/\\includegraphics[width=\\\linewidth]{$$F}/g" \
		$(TEXT_FILE).tex; \
	done;

$(DOCUMENT).pdf: $(TEXT_FILE).tex $(OBJ) ./bib/internet.bib ./bib/print.bib
	@pdflatex $(DOCUMENT)
	@bibtex $(DOCUMENT)1
	@bibtex $(DOCUMENT)2
	@echo "..."
	@pdflatex $(DOCUMENT) > /dev/null
	@pdflatex $(DOCUMENT) > /dev/null

publish: $(DOCUMENT).pdf
	scp $(DOCUMENT).pdf s0523780@charon.f4.htw-berlin.de:~/public_html/public/.

google: $(DOCUMENT).pdf
	cp $(DOCUMENT).pdf ~/Google\ Drive/.

clean:
	@echo "Delete generated files. Except the pdf."
	@find . | grep -E ".*\.(aux|gz|log|toc|out|lof|bbl|blg|dvi|bak|glo|xdy|ist)" \
		| xargs rm -f	rm -f $(TEXT_FILE).tex

cleanall: clean
	@echo "Delete pdf"
	@rm -f *.pdf
