DOCTOOL_OPTIONS = --link-to-gtk-doc --online -M $(top_srcdir) --sections-file grilo.sections.txt

PAGES_DIRECTORY = pages
PYTHON_PAGES_DIRECTORY = python_pages
YELP_HTML_DIRECTORY = yelp_html
RAKE_HTML_DIRECTORY = rake_html
BUILT_MARKDOWN_DIRECTORY = built_markdown

DOCTOOL = g-ir-doc-tool

GIRFILE = $(top_builddir)/src/Grl-0.2.gir

EXTRA_DIST = mallard_to_markdown.py

DOCS =

if BUILD_RAKE_HTML
DOCS += rake_html.stamp
endif

if ENABLE_MARKDOWN
DOCS += markdown.stamp
endif

all-local: $(DOCS)

clean-local:
	@echo "Cleaning up documentation ..."
	@rm -rf $(PAGES_DIRECTORY) $(HTML_DIRECTORY) $(BUILT_MARKDOWN_DIRECTORY) $(RAKE_HTML_DIRECTORY) rake_html.stamp yelp_html.stamp markdown.stamp pages.stamp
	@echo "Cleaned up documentation"

yelp_html.stamp: pages.stamp
	@touch yelp_html.tmp
	@echo "Building yelp html documentation ..."
	@mkdir -p yelp_html && cd yelp_html && \
	yelp-build html ../$(PAGES_DIRECTORY) && cd ..
	@mv -f yelp_html.tmp yelp_html.stamp
	@echo "Built yelp html documentation"


markdown.stamp: pages.stamp $(top_srcdir)/doc/future/mallard_to_markdown.py $(top_srcdir)/doc/future/markdown/*
	@touch markdown.tmp
	@echo "Building markdown documentation ..."
	@$(PYTHON) $(top_srcdir)/doc/future/mallard_to_markdown.py $(PAGES_DIRECTORY)/* -o $(BUILT_MARKDOWN_DIRECTORY) --python-pages $(PYTHON_PAGES_DIRECTORY) --target-format=markdown
	@cp $(top_srcdir)/doc/future/markdown/* $(BUILT_MARKDOWN_DIRECTORY)
	@mv -f markdown.tmp markdown.stamp
	@echo "Built markdown documentation ..."

rake_html.stamp: markdown.stamp
	@touch rake_html.tmp
	@echo "Building rake html documentation ..."
	@rm -rf rake_html/build
	@mkdir -p slate/source/includes
	@$(PYTHON) $(top_srcdir)/doc/future/mallard_to_markdown.py $(PAGES_DIRECTORY)/* -o slate/source/includes/ --python-pages $(PYTHON_PAGES_DIRECTORY) --target-format=slate
	@cp $(top_srcdir)/doc/future/markdown/index.md slate/source/
	@cp $(top_srcdir)/doc/future/markdown/* slate/source/includes/
	@cd slate && rake build && cd .. && cp -r slate/build $(RAKE_HTML_DIRECTORY)
	@mv -f rake_html.tmp rake_html.stamp
	@echo "Built rake html documentation"

pages.stamp: $(GIRFILE)
	@touch pages.tmp
	@echo "Generating documentation pages ..."
	@$(DOCTOOL) $(DOCTOOL_OPTIONS) $(GIRFILE) -o $(PAGES_DIRECTORY)
	@$(DOCTOOL) $(DOCTOOL_OPTIONS) $(GIRFILE) --language python -o $(PYTHON_PAGES_DIRECTORY)
	@echo "Generated documentation pages"
	@mv -f pages.tmp pages.stamp
